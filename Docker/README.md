Pull Docker Images
---
`docker pull ubuntu:22.04`

`docker pull centos:8`

Build Docker Image from Dockerfile
---
`docker build -t <image> .`

Run Docker Image
---
`docker run --rm -it -v ${PWD}:/home/test/tmp <image> /bin/bash`

Other Docker Commands
---
`docker image list`

`docker image rm <image>`