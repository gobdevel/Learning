##### Using this, you can build a custom alpine image with your own program

- To compile the cc file simply run `./compile.sh`

###### Once your custom application is ready, now its time to build our custom docker
image

- To build custome image -
```bash
docker build -t gob/kube-learn:v3 .
```

*where gob is tag and application name is kube-learn:v3*

- To run our custom image
```bash
docker run -d -p :8080 gob/kube-leaarn:v3
```

- Verify image running status
```bash
❯ docker ps
CONTAINER ID   IMAGE                COMMAND                  CREATED          STATUS          PORTS                     NAMES
ca69dc491619   gob/kube-leaarn:v3   "/bin/kubeLearningApp"   5 seconds ago    Up 4 seconds    0.0.0.0:56528->8080/tcp   sad_brown
```

Where *56528* is external port and *8080* is internal port.
Use your web browser and type address http://localhost:56528 to validate the working of image.

