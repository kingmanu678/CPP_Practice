#include <iostream>
#include <string>
using namespace std;

class ParcelAnalyzer {
public:
    // weight given in grams
    string classifyWeight(int grams) {
        if (grams < 500) return "Light";
        if (grams <= 2000) return "Medium";
        return "Heavy";
    }

    // weight given in kilograms
    string classifyWeight(float kilograms) {
        if (kilograms < 0.5f) return "Light";
        if (kilograms <= 2.0f) return "Medium";
        return "Heavy";
    }

    // weight given in pounds
    string classifyWeight(double pounds) {
        if (pounds < 1.1) return "Light";
        if (pounds <= 4.4) return "Medium";
        return "Heavy";
    }
};

// just prints the label we got
void printClassification(const string& label) {
    cout << "Classification: " << label << endl;
}

int main() {
    ParcelAnalyzer analyzer;

    cout << "Testing in grams" << endl;
    printClassification(analyzer.classifyWeight(450));
    printClassification(analyzer.classifyWeight(1500));
    printClassification(analyzer.classifyWeight(2500));

    cout << endl << "Testing in kilograms" << endl;
    printClassification(analyzer.classifyWeight(0.3f));
    printClassification(analyzer.classifyWeight(1.5f));
    printClassification(analyzer.classifyWeight(3.0f));

    cout << endl << "Testing in pounds" << endl;
    printClassification(analyzer.classifyWeight(0.9));
    printClassification(analyzer.classifyWeight(2.5));
    printClassification(analyzer.classifyWeight(5.0));

    return 0;
}
