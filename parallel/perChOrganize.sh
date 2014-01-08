#chCount=13
chCount=$1

baseDir=result

mkdir "$baseDir"/finals
mkdir "$baseDir"/executions
mkdir "$baseDir"/finals/ch$chCount/
mkdir "$baseDir"/executions/ch$chCount/

#mv "$baseDir"/final_res_"$chCount"_* "$baseDir"/finals/ch$chCount/
#mv "$baseDir"/run_res_"$chCount"_* "$baseDir"/executions/ch$chCount/

mv "$baseDir"/final_res_"$chCount"_0* "$baseDir"/finals/ch$chCount/
mv "$baseDir"/run_res_"$chCount"_0* "$baseDir"/executions/ch$chCount/

mv "$baseDir"/final_res_"$chCount"_1* "$baseDir"/finals/ch$chCount/
mv "$baseDir"/run_res_"$chCount"_1* "$baseDir"/executions/ch$chCount/

mv "$baseDir"/final_res_"$chCount"_2* "$baseDir"/finals/ch$chCount/
mv "$baseDir"/run_res_"$chCount"_2* "$baseDir"/executions/ch$chCount/

mv "$baseDir"/final_res_"$chCount"_3* "$baseDir"/finals/ch$chCount/
mv "$baseDir"/run_res_"$chCount"_3* "$baseDir"/executions/ch$chCount/

ALGO=NSGA2
algoID=0

mkdir "$baseDir"/finals/ch$chCount/$ALGO
mv "$baseDir"/finals/ch$chCount/final_res_"$chCount"_"$algoID"_* "$baseDir"/finals/ch$chCount/$ALGO/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/txt
mv "$baseDir"/finals/ch$chCount/$ALGO/*.txt "$baseDir"/finals/ch$chCount/$ALGO/txt/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/csv
mv "$baseDir"/finals/ch$chCount/$ALGO/*.csv "$baseDir"/finals/ch$chCount/$ALGO/csv/


mkdir "$baseDir"/executions/ch$chCount/$ALGO
mv "$baseDir"/executions/ch$chCount/run_res_"$chCount"_"$algoID"_* "$baseDir"/executions/ch$chCount/$ALGO/

ALGO=SPEA2
algoID=1
mkdir "$baseDir"/finals/ch$chCount/$ALGO
mv "$baseDir"/finals/ch$chCount/final_res_"$chCount"_"$algoID"_* "$baseDir"/finals/ch$chCount/$ALGO/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/txt
mv "$baseDir"/finals/ch$chCount/$ALGO/*.txt "$baseDir"/finals/ch$chCount/$ALGO/txt/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/csv
mv "$baseDir"/finals/ch$chCount/$ALGO/*.csv "$baseDir"/finals/ch$chCount/$ALGO/csv/


mkdir "$baseDir"/executions/ch$chCount/$ALGO
mv "$baseDir"/executions/ch$chCount/run_res_"$chCount"_"$algoID"_* "$baseDir"/executions/ch$chCount/$ALGO/

ALGO=IBEA
algoID=2
mkdir "$baseDir"/finals/ch$chCount/$ALGO
mv "$baseDir"/finals/ch$chCount/final_res_"$chCount"_"$algoID"_* "$baseDir"/finals/ch$chCount/$ALGO/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/txt
mv "$baseDir"/finals/ch$chCount/$ALGO/*.txt "$baseDir"/finals/ch$chCount/$ALGO/txt/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/csv
mv "$baseDir"/finals/ch$chCount/$ALGO/*.csv "$baseDir"/finals/ch$chCount/$ALGO/csv/


mkdir "$baseDir"/executions/ch$chCount/$ALGO
mv "$baseDir"/executions/ch$chCount/run_res_"$chCount"_"$algoID"_* "$baseDir"/executions/ch$chCount/$ALGO/

ALGO=MOGA
algoID=3
mkdir "$baseDir"/finals/ch$chCount/$ALGO
mv "$baseDir"/finals/ch$chCount/final_res_"$chCount"_"$algoID"_* "$baseDir"/finals/ch$chCount/$ALGO/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/txt
mv "$baseDir"/finals/ch$chCount/$ALGO/*.txt "$baseDir"/finals/ch$chCount/$ALGO/txt/
mkdir "$baseDir"/finals/ch$chCount/$ALGO/csv
mv "$baseDir"/finals/ch$chCount/$ALGO/*.csv "$baseDir"/finals/ch$chCount/$ALGO/csv/

mkdir "$baseDir"/executions/ch$chCount/$ALGO
mv "$baseDir"/executions/ch$chCount/run_res_"$chCount"_"$algoID"_* "$baseDir"/executions/ch$chCount/$ALGO/
