#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {}

    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    std::unique_ptr<tridiagonal_matrix> clone() {
        auto new_matrix = std::make_unique<tridiagonal_matrix>(
          m_down,
          m_upper,
          m_middle
        );
        return new_matrix;
    }
};

void printDoubleVectorCommaSeparated(const std::vector<double>& vectorToPrint) {
    std::string stringToPrint;
    for (auto numToPrint : vectorToPrint) {
        stringToPrint += std::to_string(numToPrint) + ", ";
    }
    stringToPrint.erase(stringToPrint.size() - 2);
    std::cout << stringToPrint;
}

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    std::cout << "New matrix:" << std::endl;
    std::cout << "{";
    printDoubleVectorCommaSeparated(matrix_clone->m_down);
    std::cout << "}" << std::endl;
    std::cout << "{";
    printDoubleVectorCommaSeparated(matrix_clone->m_upper);
    std::cout << "}" << std::endl;
    std::cout << "{";
    printDoubleVectorCommaSeparated(matrix_clone->m_middle);
    std::cout << "}" << std::endl;

    return EXIT_SUCCESS;
}