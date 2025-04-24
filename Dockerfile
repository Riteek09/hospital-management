# Use an official C++ build environment
FROM gcc:latest

# Set working directory
WORKDIR /app

# Copy current directory contents into the container
COPY . .

# Compile the C++ code
RUN g++ -o hospital main.cpp

# Run the compiled binary
CMD ["./hospital"]
