# 單一職責原則 (Single Responsibility Principle, SRP) 實作分析

本案例根據《Software Architecture with C++》第一章的觀點，分析 \`@solid/srp/example.cpp\` 中的程式碼設計。

## 1. 識別違規信號：命名中的 "And"
書中指出一個非常直觀的判別標準：
> *"Often, if you see a function [or class] with **and** in its name, it’s violating the SRP and should be refactored."*

在範例中，\`FileManagerAndParser\` 類別名稱直接揭示了它同時承擔了兩項截然不同的職責：
*   **檔案管理 (File Management)**：處理 I/O 端的讀寫。
*   **解析邏輯 (Parsing Logic)**：處理字串到資料結構的轉換。

## 2. 為什麼需要重構？
書中強調了維護成本的考量：
> *"When maintaining this class and inheriting from it, you will need to track the changes of both functionalities instead of doing it separately."*

將不同職責混合在同一個類別中會導致以下問題：
*   **多重變動原因**：無論是檔案存取方式改變，或是資料解析格式改變，都必須更動同一個類別。
*   **繼承負擔**：如果有一個子類別只需要「檔案讀寫」功能，它在繼承時會被迫帶入它不需要的「解析」功能，這增加了程式碼的複雜度與脆弱性。

## 3. 重構後的優點
範例中將其拆分為 \`FileManager\` 與 \`Parser\` 兩個類別，這帶來了明顯的架構優化：

*   **高內聚 (High Cohesion)**：每個類別只專注於一項任務，程式碼邏輯更集中、更易讀。
*   **低耦合 (Low Coupling)**：兩個模組彼此獨立，修改 \`Parser\` 的演算法不會影響到 \`FileManager\` 的穩定性。
*   **預防「上帝物件」(God Object)**：避免類別無限膨脹，成為專案中無所不知、無所不能卻也最難維護的黑洞。

## 4. 延伸建議：最少知識原則 (Law of Demeter)
除了職責拆分，書中也提到相關的「最少知識原則」：
*   一個單元應只與其關係密切的單元通訊（Talk to immediate friends）。
*   不要跟陌生人說話（Don't talk to strangers）。

將 \`FileManager\` 與 \`Parser\` 拆分後，呼叫端（Client）可以根據需求精確地與對應的模組互動，而不需要面對一個臃腫的介面。

---

## 總結
\`example.cpp\` 透過簡單的拆分，示範了如何將「混合職責」轉換為「專一職責」。這不僅符合 SRP 的定義——**「一個類別應僅有一個引起其變動的原因」**，也大大提升了程式碼的可測試性與可重用性。
