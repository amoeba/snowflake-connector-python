ARG BASE_IMAGE=quay.io/pypa/manylinux2014_x86_64
FROM $BASE_IMAGE

RUN yum install -y java-11-openjdk

# TODO: When there are prebuilt wheels accessible for our dependencies (i.e. numpy)
# for Python 3.13 this rust cargo install command can be removed.
RUN yum -y install rust cargo

# This is to solve permission issue, read https://denibertovic.com/posts/handling-permissions-with-docker-volumes/
ARG GOSU_URL=https://github.com/tianon/gosu/releases/download/1.14/gosu-amd64
ENV GOSU_PATH $GOSU_URL
RUN curl -o /usr/local/bin/gosu -SL $GOSU_PATH
RUN chmod +x /usr/local/bin/gosu

COPY scripts/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

WORKDIR /home/user
RUN chmod 777 /home/user

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
