# Move to the project root
cd "$(dirname "$0")/.."

# Set variables
BUILD_DIR="build"
NETLIST_FILE="data/example.net"
EXECUTABLE="$BUILD_DIR/simulator"

# Step 1: Configure and build
cmake -S . -B "$BUILD_DIR"
cmake --build "$BUILD_DIR"

# Step 2: Run simulation with the netlist
if [ -f "$NETLIST_FILE" ]; then
    echo "Running simulation on $NETLIST_FILE"
    "$EXECUTABLE" "$NETLIST_FILE"
else
    echo "Netlist file not found: $NETLIST_FILE"
    exit 1
fi
