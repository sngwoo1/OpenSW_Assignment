#! /bin/bash

file_wordcnt() {
	FILENAME="$1"
	if [ ! -f "$FILENAME" ]; then
		echo "$1 파일이 존재하지 않습니다."
		return 1
	fi

	word_count=$(wc -w <"$FILENAME" | awk '{print $1}')
	echo "$FILENAME 파일의 단어는 ${word_count}개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt "$FILE"
echo "file_wordcnt 함수의 종료 형태: $?"
