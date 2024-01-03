##### Using this, you can build a custom alpine image with your own program

image

- To build custome image -
```bash
docker build -t gob/ubuntu:1 .
```

- To run our custom image
```bash
docker run -d -p 2222:22 --mount source=ubuntu-data,target=/home --hostname ubuntu gob/ubuntu:1

```

- Login using ssh
```bash
ssh gobind@localhost -p 2222
```

