# RSSBotLib
[RSSBot](https://github.com/lifegpc/rssbot)使用的C++共享库。
## 构建
请使用gcc构建本项目，在Windows系统下建议使用MSYS2的MingW。
```bash
git clone --recursive https://github.com/lifegpc/rssbotlib
cd rssbotlib/src
./configure.sh  # 需要有libgnutls
./build_ffmpeg.sh
./build.sh
```
完成上述操作后即可在`src/main`看到`rssbot.dll`或`rssbot.so`。
