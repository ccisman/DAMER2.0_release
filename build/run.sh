### run.sh是一个脚本，可以对文件进行批量处理，一次性跑完所有的例子

echo "*********************************" >time_res.txt
echo "this is time result from PDNet2_0" >>time_res.txt
echo "*********************************" >>time_res.txt
for filename in ../test_programs/*.c; do
{
    # ./ps_3 $filename;
#    { ./PDNet2_0 $filename ; } 1>> time_res.txt 2>> time_res.txt
    ./PDNet2_0 -NoDependence -TraditionalSlice $filename ;
    echo $filename
}
done