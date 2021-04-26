while getopts p: flag
do
    case "${flag}" in
        p) halidePath=${OPTARG};;
    esac
done
echo "***** Compiling Halide implementation *****"
g++ ./src/ger_Blas_Halide.cpp -g -L ${halidePath}/bin -I ${halidePath}/include -I ${halidePath}/tools  -lHalide -ldl -lpthread -std=c++11 -o ./bin/ger_Blas_Halide
echo "***** Compiling C implementation *****"
gcc ./src/ger_Blas_C.c -o ./bin/ger_Blas_C

echo "***** Runing halide *****"
LD_LIBRARY_PATH=${halidePath}/bin ./bin/ger_Blas_Halide

echo "***** Runing c *****"
 ./bin/ger_Blas_C
echo "Checking Results differences... "
if diff  ./files/result_c.txt ./files/result.txt
then
    echo "Results are the same :D"
else
   echo "Results are not the same, something went wrong"
fi