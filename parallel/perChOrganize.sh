chCount=13

ALGO=NSGA2
algoID=0

mkdir finals/ch$chCount/$ALGO
mv finals/ch$chCount/final_res_"$chCount"_"$algoID"_* finals/ch$chCount/$ALGO/
mkdir finals/ch$chCount/$ALGO/txt
mv finals/ch$chCount/$ALGO/*.txt finals/ch$chCount/$ALGO/txt/
mkdir finals/ch$chCount/$ALGO/csv
mv finals/ch$chCount/$ALGO/*.csv finals/ch$chCount/$ALGO/csv/


mkdir executions/ch$chCount/$ALGO
mv executions/ch$chCount/run_res_"$chCount"_"$algoID"_* executions/ch$chCount/$ALGO/

ALGO=SPEA2
algoID=1
mkdir finals/ch$chCount/$ALGO
mv finals/ch$chCount/final_res_"$chCount"_"$algoID"_* finals/ch$chCount/$ALGO/
mkdir finals/ch$chCount/$ALGO/txt
mv finals/ch$chCount/$ALGO/*.txt finals/ch$chCount/$ALGO/txt/
mkdir finals/ch$chCount/$ALGO/csv
mv finals/ch$chCount/$ALGO/*.csv finals/ch$chCount/$ALGO/csv/


mkdir executions/ch$chCount/$ALGO
mv executions/ch$chCount/run_res_"$chCount"_"$algoID"_* executions/ch$chCount/$ALGO/

ALGO=IBEA
algoID=2
mkdir finals/ch$chCount/$ALGO
mv finals/ch$chCount/final_res_"$chCount"_"$algoID"_* finals/ch$chCount/$ALGO/
mkdir finals/ch$chCount/$ALGO/txt
mv finals/ch$chCount/$ALGO/*.txt finals/ch$chCount/$ALGO/txt/
mkdir finals/ch$chCount/$ALGO/csv
mv finals/ch$chCount/$ALGO/*.csv finals/ch$chCount/$ALGO/csv/


mkdir executions/ch$chCount/$ALGO
mv executions/ch$chCount/run_res_"$chCount"_"$algoID"_* executions/ch$chCount/$ALGO/

ALGO=MOGA
algoID=3
mkdir finals/ch$chCount/$ALGO
mv finals/ch$chCount/final_res_"$chCount"_"$algoID"_* finals/ch$chCount/$ALGO/
mkdir finals/ch$chCount/$ALGO/txt
mv finals/ch$chCount/$ALGO/*.txt finals/ch$chCount/$ALGO/txt/
mkdir finals/ch$chCount/$ALGO/csv
mv finals/ch$chCount/$ALGO/*.csv finals/ch$chCount/$ALGO/csv/

mkdir executions/ch$chCount/$ALGO
mv executions/ch$chCount/run_res_"$chCount"_"$algoID"_* executions/ch$chCount/$ALGO/
