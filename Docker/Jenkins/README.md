### Create a bridge network in Docker using the following docker network create command
<pre>
docker network create jenkins
</pre>

### Build a new docker image from this Dockerfile, and assign the image a meaningful name, such as "myjenkins-blueocean:2.440.1-1"
<pre>
docker build -t myjenkins-blueocean:2.440.1-1 .
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
  myjenkins-blueocean:2.440.1-1
</pre>

### Open Jenkins Web UI
1. Go to web browser and type http://localhost:8080
2. You will see a page "Unlock Jenkins"
   1. Unlock the Jenkins by copying the secret key `docker exec ${CONTAINER_ID or CONTAINER_NAME} cat /var/jenkins_home/secrets/initialAdminPassword`
3. 