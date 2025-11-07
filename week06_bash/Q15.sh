#! /bin/bash

file_wordcnt() {
	FILENAME="$1"
	word_count=$(wc -w <"$FILENAME")
	echo "$FILENAME 파일의 단어는 ${word_count}개 입니다."
}

read -p "Enter a file name: " FILE
file_wordcnt "$FILE"
