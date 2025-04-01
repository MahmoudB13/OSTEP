## wcat

### Description
`wcat` is a simple implementation of the Unix `cat` command, used to display the contents of a file.

### Usage
```sh
./wcat <file>
```
Example:
```sh
./wcat sample.txt
```

### Compilation
```sh
make
```

### Testing
```sh
make test
```

### Clean
```sh
make clean
```

The `test-wcat.sh` script is just a wrapper for the `run-tests.sh` script in
the `tester` directory of this repository. This program has a few options; see
the relevant
[README](https://github.com/remzi-arpacidusseau/ostep-projects/blob/master/tester/README.md)
for details.
