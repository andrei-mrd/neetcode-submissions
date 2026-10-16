class Solution:

    def encode(self, strs: List[str]) -> str:
        sir = ""
        for s in strs:
            sir+=s
            sir+="\n"
        return sir

    def decode(self, s: str) -> List[str]:
        l = []
        sir = ""
        for c in s:
            if c == "\n":
                l.append(sir)
                sir = ""
            else:
                sir+=c
        
        return l

