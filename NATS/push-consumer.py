import asyncio
import nats


async def main(loop):
    nc = await nats.connect(servers=["nats://localhost:4222"])

    async def cb(msg):
        print('Received:', msg.data.decode())  # Assuming the message payload is in bytes
        print('Metadata:', msg.headers)
    # Subscribe to the subject for push-based consumption.
    await nc.subscribe("some-subject", cb=cb)

    # Keep the event loop running to receive messages.
    await asyncio.Event().wait()

if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main(loop))
