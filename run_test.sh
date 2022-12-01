#! /bin/bash

./std_containers > out.std_containers
./ft_containers > out.ft_containers

diff out.std_containers out.ft_containers > out.std_ft.diff
diff out.std_containers out.ft_containers
