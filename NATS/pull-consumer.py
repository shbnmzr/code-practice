import asyncio
from nats.aio.client import Client as NATS


async def main(loop):
    nc = NATS()
    await nc.connect(servers=["nats://localhost:4222"])

    # Create JetStream context.
    js = nc.jetstream()

    # Ensure that the stream exists.
    await js.add_stream(name="sample-stream", subjects=["some-subject"])

    async def pull_messages():
        subscription = await js.pull_subscribe(subject="some-subject", durable="shabnam-test")

        while True:
            try:
                response = await subscription.fetch(batch=10, timeout=1)
                for msg in response:
                    await msg.ack()
                    print('Received:', msg.data.decode())
            except asyncio.TimeoutError:
                print('HERE')

    # Start the pull_messages coroutine.
    asyncio.ensure_future(pull_messages())


if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main(loop))
    loop.run_forever()
