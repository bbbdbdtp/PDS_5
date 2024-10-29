#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_5/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
        TEST_METHOD(TestGenerateCombinations) {
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

            generateCombinations();

            std::cout.rdbuf(oldCoutBuffer);

            std::string strOutput = output.str();
            Assert::IsTrue(strOutput.find("0ax") != std::string::npos);
            Assert::IsTrue(strOutput.find("0ay") != std::string::npos);
            Assert::IsTrue(strOutput.find("0az") != std::string::npos);
            Assert::IsTrue(strOutput.find("1ax") != std::string::npos);
            Assert::IsTrue(strOutput.find("1cz") != std::string::npos);
        }
        TEST_METHOD(TestPerformSetOperations) {
            std::ostringstream output;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());

            std::istringstream input("5\n1 2 3 4 5\n3\n1 3 5\n3\n2 3 4\n");
            std::cin.rdbuf(input.rdbuf());

            performSetOperations();

            std::cout.rdbuf(oldCoutBuffer);

            std::string strOutput = output.str();
            Assert::IsTrue(strOutput.find("Bit A: 1 0 1 0 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("Bit B: 0 1 1 1 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("not A: 0 1 0 1 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("AperB: 0 0 1 0 0") != std::string::npos);
            Assert::IsTrue(strOutput.find("Aob B: 1 1 1 1 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("A \\ B: 1 0 0 0 1") != std::string::npos);
            Assert::IsTrue(strOutput.find("AxorB: 1 1 0 1 1") != std::string::npos);
        }
	};
}
