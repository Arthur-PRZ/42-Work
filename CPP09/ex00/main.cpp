#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    BitcoinExchange bitcoin;
    std::ifstream bitcoinFile(argv[1]);

    (void)argc;
    bitcoin.printBitcoinValue(bitcoinFile);
}