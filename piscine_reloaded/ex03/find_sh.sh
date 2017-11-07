find . -name "*.sh" | rev | cut -c 4- | rev | sed "s/.*\///"
