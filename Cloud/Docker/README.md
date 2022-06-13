# Docker Basic Commands

To check docker version 
```bash
docker --version
```
To pull images from the docker repository
```bash
docker pull <image name>
```
To run/create container of an images
```bash
docker run -it -d <image name>
```
To list all running container 
```bash
docker ps
```
To check all running as well as exited container 
```bash
docker ps -a
```
To access/login to running container 
```bash
docker exec -it <container id> bash
```
To stops a running container 
```bash
docker stop <container id>
```
To Kill a container immediately 
```bash
docker kill <container id>
```
To creates a new image of an edited container on the local system. 
```bash 
docker commit <conatainer id> <username/imagename>
```
Login to Docker 
```bash
docker login
```
To push an image to the docker hub repository 
```bash
docker push <username/image name>
```
To lists all the locally stored docker images 
```bash
docker images
```
To delete a stopped container 
```bash
docker rm <container id>
```
To delete an image from local storage 
```bash
docker rmi <image-id>
```
To build an image from a specified docker file 
```bash
docker build <path to docker file>
```

To build an image with tag. 
```bash
docker build -t gob/kube-learn:v1 .
```
