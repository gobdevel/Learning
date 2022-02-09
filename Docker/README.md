# Docker Basic Commands

1. To check docker version `docker --version`
2. To pull images from the docker repository `docker pull <image name>`
3. To run/create container of an image `docker run -it -d <image name>`
4. To list all running container `docker ps`
5. To check all running as well as exited container `docker ps -a`
6. To access/login to running container `docker exec -it <container id> bash`
7. To stops a running container `docker stop <container id>`
8. To Kill a container immediately `docker kill <container id>`
9. To creates a new image of an edited container on the local system. `docker commit <conatainer id> <username/imagename>`
10. Login to Docker `docker login`
11. To push an image to the docker hub repository `docker push <username/image name>`
12. To lists all the locally stored docker images `docker images`
13. To delete a stopped container `docker rm <container id>`
14. To delete an image from local storage `docker rmi <image-id>`
15. To build an image from a specified docker file `docker build <path to docker file>`

16. To build an image with tag. `docker build -t gob/kube-learn:v1 .`
