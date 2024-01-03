FROM ubuntu:latest
MAINTAINER gobdeveloper@gmail.com

# Install.
RUN \
  apt-get update && \
  apt-get -y upgrade && \
  apt-get install -y build-essential && \
  apt-get install -y software-properties-common && \
  apt-get install -y byobu sudo cmake gettext curl git htop man unzip vim wget python3 python3-pip zsh && \
  apt-get install -y openssh-server && \
  mkdir /var/run/sshd && \
  git clone https://github.com/neovim/neovim && cd neovim && git checkout stable && \
  make CMAKE_BUILD_TYPE=RelWithDebInfo && make install && cd .. && rm -rf neovim && \
  rm -rf /var/lib/apt/lists/*

# Set root password
run    echo 'root:root' >> /root/passwdfile

# Create user and it's password
run    useradd -s /usr/bin/zsh -m -G sudo gobind && \
       echo 'gobind:gobind' >> /root/passwdfile

# Apply root password
run    chpasswd -c SHA512 < /root/passwdfile && \
       rm /root/passwdfile
# Add files.
# ADD root/.bashrc /root/.bashrc
# ADD root/.gitconfig /root/.gitconfig
# ADD root/.scripts /root/.scripts

# Define default command.
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
