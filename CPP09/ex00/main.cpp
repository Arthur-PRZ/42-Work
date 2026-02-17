#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    BitcoinExchange bitcoin;
    std::ifstream bitcoinFile(argv[1]);

    if (!bitcoinFile.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    bitcoin.printBitcoinValue(bitcoinFile);
}