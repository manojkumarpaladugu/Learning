Pull Docker Image
---
`docker pull ubuntu:22.04`

`docker pull centos:8`

Build Docker Image
---
`docker build -f <dockerfile> -t <image> .`

Run Docker Image
---
`docker run --rm -it -v ${PWD}:/home/test/tmp <image> /bin/bash`

Other Docker Commands
---
<pre>
List docker images  : docker image list

Remove docker image : docker image rm <image>

Clear build cache   : docker builder prune
</pre>