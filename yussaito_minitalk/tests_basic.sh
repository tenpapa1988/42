printf '    '
{ time ./client $1 "Character Counter is a 100% free online character count calculator that's simple to use. Sometimes use"; } 2>&1 | tr '\n' ' '
echo
