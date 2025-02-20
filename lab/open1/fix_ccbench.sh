echo "Installing matplotlib"
pip install matplotlib
echo "Fixing run_test.py"
cd ccbench
git apply ../run_test.patch