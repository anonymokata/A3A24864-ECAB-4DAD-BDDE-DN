FROM ubuntu:14.04

RUN apt-get update -qq && \
    apt-get upgrade -y && \
    apt-get install -y build-essential
RUN apt-get install -y cmake libgtest-dev valgrind \
    git pkg-config automake libtool

# Man pages and indent to keep myself sane
RUN apt-get install -y man-db indent
RUN apt-get install -y texinfo

# ----------- Build gtest ------------
RUN cd /usr/src/gtest && \
    cmake CMakeLists.txt && \
    make && \
    cp *.a /usr/lib
# ------------------------------------

RUN apt-get install -y vim
ENV APP_HOME /kata

# ------------ Get check ------------
RUN apt-get install check
# -------------------------------------

RUN mkdir $APP_HOME
WORKDIR $APP_HOME

#ADD . $APP_HOME/
