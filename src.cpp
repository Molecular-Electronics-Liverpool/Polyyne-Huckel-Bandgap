#include <iostream>
#include <cmath>

double const pi = 3.14159265358979323846;

double energyLeveln_plus(int n, int N, double beta1, double beta2, double alpha) {

	double arg = (2 * n * pi) / (N + 1);
	double root = std::pow(beta1, 2) + std::pow(beta2, 2) + 2 * beta1 * beta2 * std::cos(arg);
	double EnPlus = alpha + std::sqrt(root);

	return EnPlus;
}

double energyLeveln_minus(int n, int N, double beta1, double beta2, double alpha) {

	double arg = (2 * n * pi) / (N + 1);
	double root = std::pow(beta1, 2) + std::pow(beta2, 2) + 2 * beta1 * beta2 * std::cos(arg);
	double EnMinus = alpha - std::sqrt(root);

	return EnMinus;
}

double bandGap(int N, double beta1, double beta2, double alpha) {

	int HOMO = N / 2;
	int LUMO = (N / 2) + 1;

	double gap = energyLeveln_plus(HOMO, N, beta1, beta2, alpha) - energyLeveln_minus(LUMO, N, beta1, beta2, alpha);

	return gap;
}

int main() {

	int tBonds = 0;
	double beta1 = 0, beta2 = 0, alpha = 0;

	while (true) {
		std::cout << "Please enter the resonance integral for the triple bond: "; std::cin >> beta1; std::cout << "\n";
		std::cout << "Please enter the resonance integral for the single bond: "; std::cin >> beta2; std::cout << "\n";
		std::cout << "Please enter the coulomb integral for C: "; std::cin >> alpha; std::cout << "\n";
		std::cout << "Please enter the number of triple bonds to iterate up to: "; std::cin >> tBonds; std::cout << "\n";

		for (int i = 1; i <= tBonds; i++) {

			int N = 2 * i;
			double HLgap = bandGap(N, beta1, beta2, alpha);

			std::cout << HLgap << "\n";

		}
	}

	return 0;
}