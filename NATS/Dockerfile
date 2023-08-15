# Use the official NATS Docker image as the base image
FROM nats:latest

# Copy the configuration file into the container
COPY nats-server.conf /nats-server.conf

# Expose NATS and JetStream ports
EXPOSE 4222 8222

# Run the NATS server with the specified configuration file
CMD ["--config", "/nats-server.conf"]
