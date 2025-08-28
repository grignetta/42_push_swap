# push_swap

## 📖 About
`push_swap` sorts integers on stack **A** using an auxiliary stack **B** and the allowed ops:  
`sa sb ss pa pb ra rb rr rra rrb rrr`.  
This repo uses **libft** as a Git submodule.

---

## 🧠 How it works (step by step)

1) **Parse & build**  
   Inputs are validated and turned into a doubly-linked list for stack **A** (`build_list.c`, `prebuild_controls.c`).

2) **Tiny cases**  
   Length 2 → simple swap; length 3 (and sometimes 5) → small dedicated sort (`sort_aux.c`).

3) **Reduce A → B**  
   While **A** is larger than a small base (3/5) and not sorted, pick the **best candidate** to push to **B**:  
   - Compute per-node costs (see `set_cost.c`) across four rotation plans: **`rr`**, **`rrr`**, **`ra+rrb`**, **`rra+rb`**.  
   - Pick the cheapest plan and **run it**, then `pb`.

4) **Sort small A**  
   Keep the small remainder on **A** sorted.

5) **Rebuild A ← B**  
   Reinsert nodes from **B** into their correct spots in **A**:  
   - Recompute costs for nodes in **B** (`set_cost.c`).  
   - Choose the cheapest plan, run it, then `pa`.

6) **Final alignment**  
   Rotate **A** so the smallest value is on top (`sort_aux.c`).

**What’s distinctive here**
- For each chosen element, the program **selects one of four rotation plans** and **executes that plan** (not just setting flags).  
- After **every move**, positions are recalculated (`pos`, current size, top/bottom half) so each next choice reflects the **current** stacks.  
- The cost model prefers **combined rotations** (`rr`/`rrr`) when they save moves.

---

## 🛠️ Build

```bash
# clone with submodule
git clone --recurse-submodules git@github.com:grignetta/42_push_swap.git push_swap
cd push_swap

# build
make
```

---

## ▶️ Usage

```bash
# separate arguments
./push_swap 2 1 3 6 5 8

# single quoted string
./push_swap "2 1 3 6 5 8"
```

---

## ✅ Testing

Place the correct 42 checker for your OS in `tools/`:

```bash
ARG="$(seq 1 100 | shuf | tr '\n' ' ')"
./push_swap $ARG | ./tools/checker_linux $ARG   # OK/KO
./push_swap $ARG | wc -l                        # operation count
```

`tools/test.pl` wasn’t written by me — run `--help` to see its options:

```bash
perl tools/test.pl --help
```
