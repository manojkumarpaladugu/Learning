### Create a bridge network in Docker using the following docker network create command
<pre>
docker network create jenkins
</pre>

### In order to execute Docker commands inside Jenkins nodes, download and run the docker:dind Docker image using the following docker run command
`docker image pull docker:dind`

<pre>
docker run \
  --name jenkins-docker \
  --rm \
  --detach \
  --privileged \
  --network jenkins \
  --network-alias docker \
  --env DOCKER_TLS_CERTDIR=/certs \
  --volume jenkins-docker-certs:/certs/client \
  --volume jenkins-data:/var/jenkins_home \
  --publish 2376:2376 \
  docker:dind \
  --storage-driver overlay2
</pre>

### Build a new docker image from this Dockerfile, and assign the image a meaningful name, such as "myjenkins-blueocean:2.440.1-1"
<pre>
docker build -t myjenkins-blueocean:2.440.2-1 --no-cache --force-rm .
</pre>

### Run your own myjenkins-blueocean:2.440.1-1 image as a container in Docker using the following docker run command
<pre>
docker run \
  --name jenkins-blueocean \
  --restart=on-failure \
  --detach \
  --network jenkins \
  --env DOCKER_HOST=tcp://docker:2376 \
  --env DOCKER_CERT_PATH=/certs/client \
  --env DOCKER_TLS_VERIFY=1 \
  --publish 8080:8080 \
  --publish 50000:50000 \
  --volume jenkins-data:/var/jenkins_home \
  --volume jenkins-docker-certs:/certs/client:ro \
  myjenkins-blueocean:2.440.2-1
</pre>

### Open Jenkins Web UI
1. Go to web browser and type http://localhost:8080
2. Unlock the Jenkins by copying the secret key `docker exec jenkins-blueocean cat /var/jenkins_home/secrets/initialAdminPassword`

### Reference
* Installing Jenkins: https://www.jenkins.io/doc/book/installing/docker/