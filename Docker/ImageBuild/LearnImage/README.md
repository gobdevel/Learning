# Using this, you can build a custom alpine image with your own program
# Here one simple single file HTTP server is present as a template.

# To compile the cc file simply use compile.sh

# Once you custom application is ready, now its time to build our custom docker
image

# To build custome image -
docker build -t gob/kube-learn:v3 .

where gob is tag and application name is kube-learn:v3

# To run our custom image
docker run -d -p :8080 gob/kube-leaarn:v3

# docker ps
❯ docker ps
CONTAINER ID   IMAGE                COMMAND                  CREATED          STATUS          PORTS                     NAMES
ca69dc491619   gob/kube-leaarn:v3   "/bin/kubeLearningApp"   5 seconds ago    Up 4 seconds    0.0.0.0:56528->8080/tcp   sad_brown

where 56528 is external port and 8080 is internal port. Use your web browser and
type address http://localhost:56528
