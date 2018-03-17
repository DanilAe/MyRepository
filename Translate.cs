        //Translate some text of C#
        public static string Translate(string textToTranlate, string lenguage1, string Lenguage2)
        {
            string url = String.Format("https://translate.yandex.net/api/v1.5/tr/translate?key={3}&lang={0}-{1}&text={2}&format=html", this.ApiKey);
            try
            {
                XDocument document = XDocument.Load(url);
                XElement element = document.Document.Element("Translation").Element("text");
                string TranslatedText = element.Value;
                return TranslatedText;
            }
            catch
            {
                return "Ошибка.";
            }
        }
