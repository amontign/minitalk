# Minitalk

## Description

Minitalk is a project developed as part of the 42 school curriculum. It's a program that enables a server and a client to communicate using UNIX signals. This project illustrates the basics of process communication and involves deep understanding of the UNIX system calls: SIGUSR1 and SIGUSR2.

## Features

- Server and Client Communication through UNIX signals.
- Handling and processing signals reliably using sigaction.
- Client can send a string to the server, which then prints the string and sends an acknowledgment back to the client.
- Proper error handling to ensure smooth communication.

## Installation

To install and compile Minitalk, follow the steps below:

```sh
git clone https://github.com/your_username/minitalk.git
cd minitalk
make
```

## Usage

Once compiled, you can use the server and client executables to send and receive messages. First, start the server by using:

```sh
./server
```

The server will display its PID (Process ID). Open a separate terminal window and use this PID to send a message from the client, as demonstrated below:

```sh
./client [server_PID] [message]
```

For example:

```sh
./client 12345 "Hello, World!"
```
