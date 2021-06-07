# Developper build

build php :
cd <php-build>
<php-src>/configure --prefix=<php-install> ... && make && make test && make install

export PATH=<php-install>/bin:$PATH

cd <workspace>

git clone https://github.com/gtkphp/php-ext-cairo-src.git
cd php-ext-cairo-src
git checkout PHP-8.0
<php-install>/bin/phpize

//find . -name "*.c" -exec sed -i s/GTK_NS_QUOTE/CAIRO_NS_QUOTE/g {} +

cd ..
mkdir php-ext-cairo-build
mkdir php-ext-cairo-install

cd php-ext-cairo-build
../php-ext-cairo-src/configure --with-cairo --with-php-config=<php-install>/bin/php-config --prefix=/home/user/local/php-ext-cairo-install
make -j8
make install

cp .libs/cairo.so <php-install>/lib/php/extensions/no-debug-non-zts-20200930/cairo.so

export LD_LIBRARY_PATH=<php-install>/lib/php/extensions/no-debug-non-zts-20200930:$LD_LIBRARY_PATH

php -dextension=cairo.so -m | grep cairo
php -dextension=cairo.so --rc cairo_t

// TODO php.ini
PATH=<php-preffix>/bin:$PATH
TEST_PHP_ARGS=test -c /home/dev/Projects/gtkphp/php-ext-cairo-src/php-cairo.ini
TRAVIS=1
USE_ZEND_ALLOC=0
ZEND_DONT_UNLOAD_MODULES=1

make test

// TEST_PHP_EXECUTABLE=sapi/cli/php
