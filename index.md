---
layout: single
---

<style>
/* =========================
   NAV BAR
========================= */
.masthead {
  background-color: #1b5e20 !important;
}

.masthead a {
  color: white !important;
}

/* =========================
   GLOBAL LINK STYLE
========================= */
a {
  color: #1b5e20;
  font-weight: 600;
}

a:hover {
  color: #2e7d32;
}

/* =========================
   GREEN BOX (CALLOUT STYLE)
========================= */
.green-box {
  background-color: #e8f5e9;
  border: 2px solid #1b5e20;
  padding: 18px;
  border-radius: 10px;
  margin: 20px 0;
}

/* =========================
   PROJECT CARDS
========================= */
.project-card {
  background: white;
  border: 1px solid #e0e0e0;
  border-left: 5px solid #1b5e20;
  padding: 15px;
  border-radius: 10px;
  margin-bottom: 15px;
  transition: transform 0.15s ease;
}

.project-card:hover {
  transform: translateY(-2px);
}
</style>

<!-- =========================
     INTRO SECTION
========================= -->
<div class="green-box">
  <p>
    Welcome! This site contains my work in GIS, Arduino systems, wetland ecology research, and academic projects. Use the navigation bar above to explore.
  </p>
</div>

<!-- =========================
     RECENT PROJECTS
========================= -->
<div class="green-box">
  <h2>Recent Projects</h2>

  {% assign all_projects = site.projectsgis | concat: site.projectsarduino | sort: "date" | reverse %}

  {% for project in all_projects limit: 5 %}
    <div class="project-card">
      <a href="{{ project.url }}">{{ project.title }}</a><br>
      <small>{{ project.date | date: "%b %d, %Y" }}</small>
      <p>{{ project.excerpt }}</p>
    </div>
  {% endfor %}
</div>
