# This is super slow :c
FROM fedora:latest

# Don't install debug tools/libs
RUN dnf -y update && dnf -y install g++ llvm-devel make

WORKDIR /app

COPY . .

RUN make release

CMD ["./tobe"]