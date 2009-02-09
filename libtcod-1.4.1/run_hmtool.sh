export TCODDIR=$(dirname $0)
export LD_LIBRARY_PATH=.:${LD_LIBRARY_PATH}
cd ${TCODDIR} && ./hmtool $*
