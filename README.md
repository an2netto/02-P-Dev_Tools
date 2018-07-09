<p align="center">
  <b>02-P-Dev_Tools</b><br>
  <a>DFT performance tool</a>
</p>

#### Description

Measure performance time of Discrete Fourier Transform algorithm.
The source code is compiled into multiple binaries with -O0, -O1, -O2, -O3, Os gcc flags.
Performance is measured against a variable number of samples in 20 steps
within range

```python
[0..2000..100]
```
#### Dependencies
- libsndfile
- matplotlib

*Matplotlib* is a Python 2D plotting library. Install from Ubuntu Terminal:
```console
sudo apt-get install python3-matplotlib
```

You can download *libsndfile* source package [here](http://www.mega-nerd.com/libsndfile/files/libsndfile-1.0.28.tar.gz). And compile as follows:

```console
./configure --prefix=/usr    \
            --disable-static \
            --docdir=/usr/share/doc/libsndfile-1.0.28 &&
make
sudo make install
```
#### Compilation
```
clone git@github.com:an2netto/02-P-Dev_Tools.git
cd 02-P-Dev_Tools/
make
run ./script.sh
```

The script generates a *data.txt* file with performance stats plotted to a *plot.png*.
