cd thirdparty/ffmpeg
./configure --enable-gpl --enable-version3 --libdir=./ --disable-programs --disable-encoders \
--disable-asm --disable-decoders --disable-hwaccels --disable-muxers --disable-bsfs \
--disable-devices --disable-filters --enable-gnutls --enable-muxer=mp4 --enable-muxer=matroska
