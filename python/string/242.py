class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        alphabet = [0] * 26
        for i in range(0, len(s)):
            alphabet[ord(s[i])-ord('a')] += 1
        for i in range(0, len(t)):
            alphabet[ord(t[i])-ord('a')] -= 1
            if alphabet[ord(t[i])-ord('a')] < 0:
                return False
        return True
        