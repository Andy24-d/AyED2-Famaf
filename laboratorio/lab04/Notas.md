-----------Notas-----------------

Valgrind: Permite ver alloc y free usados.
1. Crear ejecutable con gcc
2. $> valgrind ./executable

$> valgrind ./executable

Mas detallado:
$> valgrind -s --leak-check=full --show-leak-kinds=all ./main

Ver espacio que ocupa el archivo
ls -l archivo
ls -lh archivo (lh human readable)
