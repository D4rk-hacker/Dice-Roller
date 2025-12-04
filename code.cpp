#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

class DiceSimulator {
private:
    vector<int> history;
    const int MAX_HISTORY = 20;
    mt19937 rng;

public:
    DiceSimulator() {
        random_device rd;
        rng = mt19937(rd());
    }

    int rollDie() {
        uniform_int_distribution<int> dist(1,6);
        return dist(rng);
    }

    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void rollDice(int num = 2) {
        clearScreen();
        vector<int> results;

        cout << "🎲 Dice Roll Simulator 🎲" << string(30, '=') << endl;
        cout << "Rolling " << num << " dice...\n\n";

        for (int i = 0; i < num; i++) {
            int result = rollDie();
            results.push_back(result);
            cout << "Dice " << (i+1) << ": ";

            // Visual dice faces
            switch(result) {
                case 1: cout << "⚀"; break;
                case 2: cout << "⚁"; break;
                case 3: cout << "⚂"; break;
                case 4: cout << "⚃"; break;
                case 5: cout << "⚄"; break;
                case 6: cout << "⚅"; break;
            }
            cout << " (" << result << ")\n";
        }

        int total = accumulate(results.begin(), results.end(), 0);
        cout << "\n📊 Total: " << total << " | Average: " << fixed << setprecision(2) << (double)total/num << "\n";

        addToHistory(results);
        showStats();
        showMenu();
    }

    void addToHistory(const vector<int>& roll) {
        for (int r : roll) {
            history.insert(history.begin(), r);
            if ((int)history.size() > MAX_HISTORY)
                history.pop_back();
        }
    }

    void showStats() {
        cout << "\n📈 Roll History (last 20 rolls):\n";
        for (size_t i = 0; i < min(history.size(), (size_t)20); i++) {
            cout << history[i] << " ";
        }
        cout << "\n";
        if (!history.empty()) {
            int minVal = *min_element(history.begin(), history.end());
            int maxVal = *max_element(history.begin(), history.end());
            cout << "\n📊 Stats: Rolls: " << history.size() << " | Min: " << minVal << " | Max: " << maxVal << "\n";
        }
    }

    void showMenu() {
        cout << "\n🎮 Commands:\n";
        cout << "1. Roll 1 dice\n";
        cout << "2. Roll 2 dice\n";
        cout << "3. Roll 3 dice\n";
        cout << "4. Clear history\n";
        cout << "5. Show stats\n";
        cout << "0. Quit\n";
        cout << "> ";
    }

    void run() {
        int choice = -1;
        rollDice(2); // initial roll

        while (true) {
            cin >> choice;
            if (choice == 0) break;
            switch (choice) {
                case 1: rollDice(1); break;
                case 2: rollDice(2); break;
                case 3: rollDice(3); break;
                case 4: 
                    history.clear();
                    cout << "History cleared!\n";
                    break;
                case 5:
                    showStats();
                    break;
                default:
                    cout << "Invalid choice!\n";
                    break;
            }
            if (choice != 5) showMenu();
        }
    }
};

int main() {
    DiceSimulator sim;
    sim.run();
    return 0;
}
