import asyncio
import nats


async def main():
    nc = await nats.connect(servers=["nats://localhost:4222"])

    # Create JetStream context.
    js = nc.jetstream()

    # Persist messages on the subject.
    await js.add_stream(name="sample-stream", subjects=["some-subject"])

    for i in range(0, 10):
        ack = await js.publish("some-subject", f"hello world: {i}".encode(), headers={
            'author': 'Somebody',
        })
        ## Additional data can be passed inside the header as a dictionary
        print(ack)

    await nc.close()


if __name__ == '__main__':
    asyncio.run(main())
