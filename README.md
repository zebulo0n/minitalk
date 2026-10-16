*This project has been created as part of the 42 curriculum by zoeschne.*

# minitalk

A client/server pair that transmits strings using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

## Usage

```sh
make
./server            # prints its PID
./client <PID> "Hello!"
```
