struct Trie
{
    int words;
    int prefixes;
    Trie* edges[26];
    Trie(){
        words = 0;
        prefixes = 0;
        for(int i = 0;i < 26; i++)
            edges[i] = NULL;
    }
 
  bool containsKey(char ch)
  {
    return (edges[ch-'a']!=NULL);
  }


};

Trie* root=new Trie();
void add(string word)
{
  Trie* now=root;
  for(int i=0;i<word.size();i++)
  {
        now->prefixes++;
        if(!now->containsKey(word[i]))
        {
             now->edges[word[i]-'a']= new Trie();
        }
        now= now->edges[word[i]-'a'];

  }
 now->prefixes++;
 now->words++;

}
int countWords(string word)
{
    Trie* now= root;
    for(int i=0;i<word.size();i++)
    {
        if(!now->containsKey(word[i])){return 0;}
        now= now->edges[word[i]-'a'];
    }
    return now->words;

}
int countPrefix(string word)
{
      Trie* now= root;
  for(int i=0;i<word.size();i++)
    {
        if(!now->containsKey(word[i])){return 0;}
        now= now->edges[word[i]-'a'];
    }
    return now->prefixes;     
}
void Trie_Init()
{
 root->prefixes=0;
 root->words=0;
 for(int i=0;i<26;i++)
 {
    root->edges[i]=NULL;
 }
 


}
