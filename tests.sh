echo "ls - ft_ls"
	 ls -1 > sorties/sortie_ls
./ft_ls -1 > sorties/sortie_ft

	 ls -1 . > sorties/sortie_ls_point
./ft_ls -1 . > sorties/sortie_ft_point

	 ls -1 / > sorties/sortie_ls_slash
./ft_ls -1 / > sorties/sortie_ft_slash

	 ls -1 ~/ > sorties/sortie_ls_tild
./ft_ls -1 ~/ > sorties/sortie_ft_tild

	 ls -1 libft inconnu Makefile auteur src > sorties/sortie_ls_multi
./ft_ls -1 libft inconnu Makefile auteur src > sorties/sortie_ft_multi

	 ls -1 inconnu inconnu2 > sorties/sortie_ls_nonex
./ft_ls -1 inconnu inconnu2 > sorties/sortie_ft_nonex

	 ls -1 src libft > sorties/sortie_ls_direc
./ft_ls -1 src libft > sorties/sortie_ft_direc

	 ls -1 auteur Makefile > sorties/sortie_ls_files
./ft_ls -1 auteur Makefile > sorties/sortie_ft_files

	 ls -1 /dev > sorties/sortie_ls_dev
./ft_ls -1 /dev > sorties/sortie_ft_dev

	 ls -1 /bin > sorties/sortie_ls_bin
./ft_ls -1 /bin > sorties/sortie_ft_bin

	 ls -1 /Users > sorties/sortie_ls_users
./ft_ls -1 /Users > sorties/sortie_ft_users

echo "\nls -a - ft_ls -a"
	 ls -1a > sorties/sortie_ls_all
./ft_ls -1a > sorties/sortie_ft_all

	 ls -1a . > sorties/sortie_ls_allpoint
./ft_ls -1a . > sorties/sortie_ft_allpoint

	 ls -1a / > sorties/sortie_ls_allslash
./ft_ls -1a / > sorties/sortie_ft_allslash

	 ls -1a ~/ > sorties/sortie_ls_alltild
./ft_ls -1a ~/ > sorties/sortie_ft_alltild

	 ls -1a libft inconnu Makefile auteur src > sorties/sortie_ls_allmulti
./ft_ls -1a libft inconnu Makefile auteur src > sorties/sortie_ft_allmulti

	 ls -1a inconnu inconnu2 > sorties/sortie_ls_allnonex
./ft_ls -1a inconnu inconnu2 > sorties/sortie_ft_allnonex

	 ls -1a src libft > sorties/sortie_ls_alldirec
./ft_ls -1a src libft > sorties/sortie_ft_alldirec

	 ls -1a auteur Makefile > sorties/sortie_ls_allfiles
./ft_ls -1a auteur Makefile > sorties/sortie_ft_allfiles

	 ls -1a /dev > sorties/sortie_ls_alldev
./ft_ls -1a /dev > sorties/sortie_ft_alldev

	 ls -1a /bin > sorties/sortie_ls_allbin
./ft_ls -1a /bin > sorties/sortie_ft_allbin

	 ls -1a /Users > sorties/sortie_ls_allusers
./ft_ls -1a /Users > sorties/sortie_ft_allusers

echo "\nls -t - ft_ls -t"
	 ls -1t > sorties/sortie_ls_time
./ft_ls -1t > sorties/sortie_ft_time

	 ls -1t . > sorties/sortie_ls_timepoint
./ft_ls -1t . > sorties/sortie_ft_timepoint

	 ls -1t / > sorties/sortie_ls_timeslash
./ft_ls -1t / > sorties/sortie_ft_timeslash

	 ls -1t ~/ > sorties/sortie_ls_timetild
./ft_ls -1t ~/ > sorties/sortie_ft_timetild

	 ls -1t libft inconnu Makefile auteur src > sorties/sortie_ls_timemulti
./ft_ls -1t libft inconnu Makefile auteur src > sorties/sortie_ft_timemulti

	 ls -1t inconnu inconnu2 > sorties/sortie_ls_timenonex
./ft_ls -1t inconnu inconnu2 > sorties/sortie_ft_timenonex

	 ls -1t src libft > sorties/sortie_ls_timedirec
./ft_ls -1t src libft > sorties/sortie_ft_timedirec

	 ls -1t auteur Makefile > sorties/sortie_ls_timefiles
./ft_ls -1t auteur Makefile > sorties/sortie_ft_timefiles

	 ls -1t /dev > sorties/sortie_ls_timedev && ./ft_ls -1t /dev > sorties/sortie_ft_timedev

	 ls -1t /bin > sorties/sortie_ls_timebin
./ft_ls -1t /bin > sorties/sortie_ft_timebin

	 ls -1t /Users > sorties/sortie_ls_timeusers
./ft_ls -1t /Users > sorties/sortie_ft_timeusers

echo "\nls -r - ft_ls -r"
	 ls -1r > sorties/sortie_ls_reverse
./ft_ls -1r > sorties/sortie_ft_reverse

	 ls -1r . > sorties/sortie_ls_reversepoint
./ft_ls -1r . > sorties/sortie_ft_reversepoint

	 ls -1r / > sorties/sortie_ls_reverseslash
./ft_ls -1r / > sorties/sortie_ft_reverseslash

	 ls -1r ~/ > sorties/sortie_ls_reversetild
./ft_ls -1r ~/ > sorties/sortie_ft_reversetild

	 ls -1r libft inconnu Makefile auteur src > sorties/sortie_ls_reversemulti
./ft_ls -1r libft inconnu Makefile auteur src > sorties/sortie_ft_reversemulti

	 ls -1r inconnu inconnu2 > sorties/sortie_ls_reversenonex
./ft_ls -1r inconnu inconnu2 > sorties/sortie_ft_reversenonex

	 ls -1r src libft > sorties/sortie_ls_reversedirec
./ft_ls -1r src libft > sorties/sortie_ft_reversedirec

	 ls -1r auteur Makefile > sorties/sortie_ls_reversefiles
./ft_ls -1r auteur Makefile > sorties/sortie_ft_reversefiles

	 ls -1r /dev > sorties/sortie_ls_reversedev
./ft_ls -1r /dev > sorties/sortie_ft_reversedev

	 ls -1r /bin > sorties/sortie_ls_reversebin
./ft_ls -1r /bin > sorties/sortie_ft_reversebin

	 ls -1r /Users > sorties/sortie_ls_reverseusers
./ft_ls -1r /Users > sorties/sortie_ft_reverseusers

	 ls -1r /dev > sorties/sortie_ls_reversedev
./ft_ls -1r /dev > sorties/sortie_ft_reversedev

	 ls -1r /bin > sorties/sortie_ls_reversebin
./ft_ls -1r /bin > sorties/sortie_ft_reversebin

	 ls -1r /Users > sorties/sortie_ls_reverseusers
./ft_ls -1r /Users > sorties/sortie_ft_reverseusers

echo "\nls -at - ft_ls -at"
	 ls -1at > sorties/sortie_ls_alltime
./ft_ls -1at > sorties/sortie_ft_alltime

	 ls -1at . > sorties/sortie_ls_alltimepoint
./ft_ls -1at . > sorties/sortie_ft_alltimepoint

	 ls -1at / > sorties/sortie_ls_alltimeslash
./ft_ls -1at / > sorties/sortie_ft_alltimeslash

	 ls -1at ~/ > sorties/sortie_ls_alltimetild
./ft_ls -1at ~/ > sorties/sortie_ft_alltimetild

	 ls -1at libft inconnu Makefile auteur src > sorties/sortie_ls_alltimemulti
./ft_ls -1at libft inconnu Makefile auteur src > sorties/sortie_ft_alltimemulti

	 ls -1at inconnu inconnu2 > sorties/sortie_ls_alltimenonex
./ft_ls -1at inconnu inconnu2 > sorties/sortie_ft_alltimenonex

	 ls -1at src libft > sorties/sortie_ls_alltimedirec
./ft_ls -1at src libft > sorties/sortie_ft_alltimedirec

	 ls -1at auteur Makefile > sorties/sortie_ls_alltimefiles
./ft_ls -1at auteur Makefile > sorties/sortie_ft_alltimefiles

	 ls -1at /dev > sorties/sortie_ls_alltimedev
./ft_ls -1at /dev > sorties/sortie_ft_alltimedev

	 ls -1at /bin > sorties/sortie_ls_alltimebin
./ft_ls -1at /bin > sorties/sortie_ft_alltimebin

	 ls -1at /Users > sorties/sortie_ls_alltimeusers
./ft_ls -1at /Users > sorties/sortie_ft_alltimeusers

echo "\nls -ar - ft_ls -ar"
	 ls -1ar > sorties/sortie_ls_allreverse
./ft_ls -1ar > sorties/sortie_ft_allreverse

	 ls -1ar . > sorties/sortie_ls_allreversepoint
./ft_ls -1ar . > sorties/sortie_ft_allreversepoint

	 ls -1ar / > sorties/sortie_ls_allreverseslash
./ft_ls -1ar / > sorties/sortie_ft_allreverseslash

	 ls -1ar ~/ > sorties/sortie_ls_allreversetild
./ft_ls -1ar ~/ > sorties/sortie_ft_allreversetild

	 ls -1ar libft inconnu Makefile auteur src > sorties/sortie_ls_allreversemulti
./ft_ls -1ar libft inconnu Makefile auteur src > sorties/sortie_ft_allreversemulti

	 ls -1ar inconnu inconnu2 > sorties/sortie_ls_allreversenonex
./ft_ls -1ar inconnu inconnu2 > sorties/sortie_ft_allreversenonex

	 ls -1ar src libft > sorties/sortie_ls_allreversedirec
./ft_ls -1ar src libft > sorties/sortie_ft_allreversedirec

	 ls -1ar auteur Makefile > sorties/sortie_ls_allreversefiles
./ft_ls -1ar auteur Makefile > sorties/sortie_ft_allreversefiles

	 ls -1ar /dev > sorties/sortie_ls_allreversedev
./ft_ls -1ar /dev > sorties/sortie_ft_allreversedev

	 ls -1ar /bin > sorties/sortie_ls_allreversebin
./ft_ls -1ar /bin > sorties/sortie_ft_allreversebin

	 ls -1ar /Users > sorties/sortie_ls_allreverseusers
./ft_ls -1ar /Users > sorties/sortie_ft_allreverseusers

echo "\nls -tr - ft_ls -tr"
	 ls -1tr > sorties/sortie_ls_timereverse
./ft_ls -1tr > sorties/sortie_ft_timereverse

	 ls -1tr . > sorties/sortie_ls_timereversepoint
./ft_ls -1tr . > sorties/sortie_ft_timereversepoint

	 ls -1tr / > sorties/sortie_ls_timereverseslash
./ft_ls -1tr / > sorties/sortie_ft_timereverseslash

	 ls -1tr ~/ > sorties/sortie_ls_timereversetild
./ft_ls -1tr ~/ > sorties/sortie_ft_timereversetild

	 ls -1tr libft inconnu Makefile auteur src > sorties/sortie_ls_timereversemulti
./ft_ls -1tr libft inconnu Makefile auteur src > sorties/sortie_ft_timereversemulti

	 ls -1tr inconnu inconnu2 > sorties/sortie_ls_timereversenonex
./ft_ls -1tr inconnu inconnu2 > sorties/sortie_ft_timereversenonex

	 ls -1tr src libft > sorties/sortie_ls_timereversedirec
./ft_ls -1tr src libft > sorties/sortie_ft_timereversedirec

	 ls -1tr auteur Makefile > sorties/sortie_ls_timereversefiles
./ft_ls -1tr auteur Makefile > sorties/sortie_ft_timereversefiles

	 ls -1tr /dev > sorties/sortie_ls_timereversedev
./ft_ls -1tr /dev > sorties/sortie_ft_timereversedev

	 ls -1tr /bin > sorties/sortie_ls_timereversebin
./ft_ls -1tr /bin > sorties/sortie_ft_timereversebin

	 ls -1tr /Users > sorties/sortie_ls_timereverseusers
./ft_ls -1tr /Users > sorties/sortie_ft_timereverseusers

echo "\nls -atr - ft_ls -atr"
	 ls -1atr > sorties/sortie_ls_alltimereverse
./ft_ls -1atr > sorties/sortie_ft_alltimereverse

	 ls -1atr . > sorties/sortie_ls_alltimereversepoint
./ft_ls -1atr . > sorties/sortie_ft_alltimereversepoint

	 ls -1atr / > sorties/sortie_ls_alltimereverseslash
./ft_ls -1atr / > sorties/sortie_ft_alltimereverseslash

	 ls -1atr ~/ > sorties/sortie_ls_alltimereversetild
./ft_ls -1atr ~/ > sorties/sortie_ft_alltimereversetild

	 ls -1atr libft inconnu Makefile auteur src > sorties/sortie_ls_alltimereversemulti
./ft_ls -1atr libft inconnu Makefile auteur src > sorties/sortie_ft_alltimereversemulti

	 ls -1atr inconnu inconnu2 > sorties/sortie_ls_alltimereversenonex
./ft_ls -1atr inconnu inconnu2 > sorties/sortie_ft_alltimereversenonex

	 ls -1atr src libft > sorties/sortie_ls_alltimereversedirec
./ft_ls -1atr src libft > sorties/sortie_ft_alltimereversedirec

	 ls -1atr auteur Makefile > sorties/sortie_ls_alltimereversefiles
./ft_ls -1atr auteur Makefile > sorties/sortie_ft_alltimereversefiles

	 ls -1atr /dev > sorties/sortie_ls_alltimereversedev
./ft_ls -1atr /dev > sorties/sortie_ft_alltimereversedev

	 ls -1atr /bin > sorties/sortie_ls_alltimereversebin
./ft_ls -1atr /bin > sorties/sortie_ft_alltimereversebin

	 ls -1atr /Users > sorties/sortie_ls_alltimereverseusers
./ft_ls -1atr /Users > sorties/sortie_ft_alltimereverseusers

echo "\nls -R - ft_ls -R"
	 ls -1R > sorties/sortie_ls_recur
./ft_ls -1R > sorties/sortie_ft_recur

	 ls -1R . > sorties/sortie_ls_recurpoint
./ft_ls -1R . > sorties/sortie_ft_recurpoint

	 ls -1R / > sorties/sortie_ls_recurslash
./ft_ls -1R / > sorties/sortie_ft_recurslash

	 ls -1R ~/ > sorties/sortie_ls_recurtild
./ft_ls -1R ~/ > sorties/sortie_ft_recurtild

	 ls -1R libft inconnu Makefile auteur src > sorties/sortie_ls_recurmulti
./ft_ls -1R libft inconnu Makefile auteur src > sorties/sortie_ft_recurmulti

	 ls -1R inconnu inconnu2 > sorties/sortie_ls_recurnonex
./ft_ls -1R inconnu inconnu2 > sorties/sortie_ft_recurnonex

	 ls -1R src libft > sorties/sortie_ls_recurdirec
./ft_ls -1R src libft > sorties/sortie_ft_recurdirec

	 ls -1R auteur Makefile > sorties/sortie_ls_recurfiles
./ft_ls -1R auteur Makefile > sorties/sortie_ft_recurfiles

	 ls -1R /dev > sorties/sortie_ls_recurdev
./ft_ls -1R /dev > sorties/sortie_ft_recurdev

	 ls -1R /bin > sorties/sortie_ls_recurbin
./ft_ls -1R /bin > sorties/sortie_ft_recurbin

	 ls -1R /Users > sorties/sortie_ls_recurusers
./ft_ls -1R /Users > sorties/sortie_ft_recurusers
