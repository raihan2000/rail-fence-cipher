# Rail Fence Cipher

About Rail Fence Cipher : https://en.wikipedia.org/wiki/Rail_fence_cipher


## Installation
Download rail-fence-cipher by cloning the Git repository:

    git clone https://github.com/raihan2000/rail-fence-cipher.git
    cd rail-fence-cipher
    make rail
    
## Usage
    
    ./rail -h or ./rail --help

## Usage example

This will print decrypted file.txt or String

    ./rail -dl LayerNumber [File or String]
    echo "Somthing" | ./rail -dl LayerNumber

To encrypt just omit -d

    ./rail -l LayerNumber [File or String]
    echo "Encrypted Text" | ./rail -l LayerNumber
