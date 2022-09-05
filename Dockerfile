FROM archlinux
RUN pacman -Syu     --noconfirm \
&& pacman -S git    --noconfirm \
&& pacman -S g++    --noconfirm \
&& pacman -S make   --noconfirm \
&& pacman -S wget   --noconfirm \
&& pacman -S ncurse --noconfirms\
&& wget https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-linux.tar.gz \
&& tar -xvzf premake-5.0.0-beta2-linux.tar.gz \
&& chmod +x premake5 \
&& mv premake5 /bin


RUN git clone https://github.com/abhigyandabla/asciitube
