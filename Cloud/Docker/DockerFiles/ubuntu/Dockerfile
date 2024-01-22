FROM ubuntu:latest
MAINTAINER gobdeveloper@gmail.com

# Install.
RUN \
  apt-get update && \
  apt-get -y upgrade && \
  apt-get install -y build-essential && \
  apt-get install -y software-properties-common && \
  apt-get install -y byobu sudo cmake gettext curl git htop man unzip vim \
  wget python3 python3-pip python3-venv zsh apt-transport-https ca-certificates && \
  apt-get install -y openssh-server && \
  mkdir -p /var/run/sshd /etc/apt/keyrings && \
  curl https://packages.cloud.google.com/apt/doc/apt-key.gpg | gpg --dearmor -o /usr/share/keyrings/cloud.google.gpg && \
  echo "deb [signed-by=/usr/share/keyrings/cloud.google.gpg] https://packages.cloud.google.com/apt cloud-sdk main" | \
    tee -a /etc/apt/sources.list.d/google-cloud-sdk.list && \
  curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg && \
  echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu  \
    $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/docker.list > /dev/null && \
  apt-get update && apt-get -y install google-cloud-cli docker-ce docker-ce-cli containerd.io docker-compose-plugin && \
  rm -rf /var/lib/apt/lists/*

# git clone https://github.com/neovim/neovim && cd neovim && git checkout stable && \
# make CMAKE_BUILD_TYPE=RelWithDebInfo && make install && cd .. && rm -rf neovim && \

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
