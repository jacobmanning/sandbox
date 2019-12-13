find . -iname '*.cc' -not -path './ThirdParty/*' | xargs clang-format -i
find . -iname '*.hh' -not -path './ThirdParty/*' | xargs clang-format -i
find . -iname '*.inl' -not -path './ThirdParty/*' | xargs clang-format -i
