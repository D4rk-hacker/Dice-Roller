# 🎲 Dice Roll Simulator
High-performance C++ console application for dice rolling with statistics, history tracking, and cross-platform support. Perfect for RPGs, board games, or teaching randomization algorithms.

✨ Features
Multi-dice rolls - Roll 1-3 dice at once (1d6 standard)

Visual Unicode dice - Realistic dice faces (⚀⚁⚂⚃⚄⚅)

Roll history - Track last 20 rolls with min/max stats

Real-time stats - Total sum and average per roll

Cross-platform - Windows/Linux/macOS (auto-detects clear screen)

Mersenne Twister RNG - Cryptographically strong randomness

🎯 Quick Start
bash
g++ -std=c++17 -O2 dice.cpp -o dice
./dice  # Linux/Mac
dice.exe  # Windows
